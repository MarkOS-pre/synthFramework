/*
  ==============================================================================

    SynthVoice.h
    Created: 11 Jun 2025 11:16:52pm
    Author:  Marcos

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SynthSound.h"
#include "maximilian.h"

class SynthVoice : public juce::SynthesiserVoice
{
public:
    bool canPlaySound(juce::SynthesiserSound* sound)
    {
        /* Verifica si el puntero sound es de tipo SynthSound*/
        return dynamic_cast<SynthSound*>(sound) != nullptr;
    }

    /*********************************************************/

    void getParam(float* attack, float* decay, float* sustain, float* release)
    {
        env1.setAttack(double(*attack));
        env1.setDecay(double(*decay));
        env1.setAttack(double(*sustain));
        env1.setRelease(double(*release));
    }

    //***************************************************

    void startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition)
    {
        env1.trigger = 1;
        level = velocity;
        frequency = juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        DBG("midi: "<<midiNoteNumber);
    }
    //***************************************************
    void stopNote(float velocity, bool allowTailOff)
    {
        env1.trigger = 0;
        allowTailOff = true;

        if(velocity == 0)
            clearCurrentNote();
    }
    //***************************************************
    void pitchWheelMoved(int newPitchWheelValue)
    {
        
    }
    //***************************************************
    void controllerMoved(int controllerNumber,
        int	newControllerValue)
    {

    }

    //***************************************************
    void renderNextBlock(juce::AudioBuffer< float >& outputBuffer, int	startSample, int	numSamples)
    {
        
        env1.setDecay(500);
        env1.setSustain(0.8);
        

        for (int sample = 0; sample < numSamples; sample++)
        {
            double theWave = osc1.sinewave(frequency);
            double theSound = env1.adsr(theWave, env1.trigger) * level;
            double filteredSound = filter1.lores(theSound, 200, 0.1);
            for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
            {
                outputBuffer.addSample(channel, startSample, filteredSound);
            }
            ++startSample;
        }
    }
private:
    float level;
    double frequency;

    maxiOsc osc1;
    maxiEnv env1;
    maxiFilter filter1;

};
