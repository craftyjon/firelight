// Firelight
// Copyright (c) 2013 Jon Evans
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "audio_manager.h"

AudioManager::AudioManager()
{
    _initialized = false;
    _stream = NULL;
    qDebug() << "Opening input stream...";
    InitAudio();
}


AudioManager::~AudioManager()
{
    DeInitAudio();
}


void AudioManager::InitAudio()
{
    PaStreamParameters pars;
    PaError err;

    err = Pa_Initialize();

    if (err != paNoError)
    {
        qDebug() << "Could not initialize portaudio.";
        return;
    }

    pars.device = Pa_GetDefaultInputDevice();

    if (pars.device == paNoDevice)
    {
        qDebug() << "No audio input device available.";
        return;
    }

    pars.channelCount = 1;
    pars.sampleFormat = PA_SAMPLE_TYPE;
    pars.suggestedLatency = Pa_GetDeviceInfo(pars.device)->defaultLowInputLatency;
    pars.hostApiSpecificStreamInfo = NULL;

    err = Pa_OpenStream(&_stream,
                        &pars,
                        NULL,
                        SAMPLE_RATE,
                        FRAMES_PER_BUFFER,
                        0,
                        &AudioManager::PortAudioCallbackWrapper,
                        NULL );


    if (err != paNoError)
    {
        qDebug() << "Error opening portaudio stream.";
    }

    err = Pa_StartStream(_stream);

    if (err != paNoError)
    {
        qDebug() << "Error starting portaudio stream.";
        return;
    }

    qDebug() << "Portaudio input stream is running.";

    _initialized = true;
}


void AudioManager::DeInitAudio()
{
    PaError err = Pa_CloseStream(_stream);
    if(err != paNoError)
    {
        qDebug() << "Warning: portaudio returned error while closing stream.";
    }

    Pa_Terminate();

    qDebug() << "Portaudio input stream shutdown.";

    _initialized = false;
}


int AudioManager::PortAudioCallback(const void *inputBuffer, void *outputBuffer,
                                    unsigned long framesPerBuffer,
                                    const PaStreamCallbackTimeInfo* timeInfo,
                                    PaStreamCallbackFlags statusFlags)
{
    Q_UNUSED(timeInfo)
    Q_UNUSED(statusFlags)
    Q_UNUSED(outputBuffer)

    const float *in = (const float*)inputBuffer;



    return paContinue;
}
