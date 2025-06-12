/*
  ==============================================================================

    SynthSound.h
    Created: 11 Jun 2025 11:16:35pm
    Author:  Marcos

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound
{
public:
    bool appliesToNote(int /*midiNoteNumber*/)
    {
        return true;
    }

    bool appliesToChannel(int /*midiChannel*/)
    {
        return true;
    }
};
