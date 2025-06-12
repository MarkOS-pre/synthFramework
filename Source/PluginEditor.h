/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class SynthFrameworkAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                            public juce::Slider::Listener
                                            
{
public:
    SynthFrameworkAudioProcessorEditor (SynthFrameworkAudioProcessor&);
    ~SynthFrameworkAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    void sliderValueChanged(juce::Slider* slider)
    {
        if (slider == &attackSlider)
        {
            audioProcessor.attackTime = attackSlider.getValue();
        }
        else if (slider == &releaseSlider) {
            audioProcessor.releaseTime = releaseSlider.getValue();
        }
        else if (slider == &decaySlider) {
            audioProcessor.decayTime = decaySlider.getValue();
        }
        else if (slider == &sustainSlider) {
            audioProcessor.sustainTime = sustainSlider.getValue();
        }
    }

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SynthFrameworkAudioProcessor& audioProcessor;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> attackTree;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> decayTree;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> sustainTree;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> releaseTree;

    juce::Slider attackSlider;
    juce::Slider decaySlider;
    juce::Slider sustainSlider;
    juce::Slider releaseSlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthFrameworkAudioProcessorEditor)
};
