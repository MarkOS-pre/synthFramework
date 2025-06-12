/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SynthFrameworkAudioProcessorEditor::SynthFrameworkAudioProcessorEditor (SynthFrameworkAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

    attackSlider.setSliderStyle(juce::Slider::LinearVertical);
    attackSlider.setRange(0.1f, 5000.0f);
    attackSlider.setValue(0.1f);
    attackSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 20.0, 10.0);
    attackSlider.addListener(this);

    attackTree = std::make_unique <juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.tree, "Attack", attackSlider);
    addAndMakeVisible(attackSlider);

    releaseSlider.setSliderStyle(juce::Slider::LinearVertical);
    releaseSlider.setRange(0.1f, 5000.0f);
    releaseSlider.setValue(0.1f);
    releaseSlider.addListener(this);
    releaseSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 20.0, 10.0);

    releaseTree = std::make_unique <juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.tree, "Release", releaseSlider);

    addAndMakeVisible(releaseSlider);

    decaySlider.setSliderStyle(juce::Slider::LinearVertical);
    decaySlider.setRange(0.1f, 5000.0f);
    decaySlider.setValue(0.1f);
    decaySlider.addListener(this);
    decaySlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 20.0, 10.0);

    decayTree = std::make_unique <juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.tree, "Decay", decaySlider);

    addAndMakeVisible(decaySlider);

    sustainSlider.setSliderStyle(juce::Slider::LinearVertical);
    sustainSlider.setRange(0.1f, 5000.0f);
    sustainSlider.setValue(0.1f);
    sustainSlider.addListener(this);
    sustainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 20.0, 10.0);

    sustainTree = std::make_unique <juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.tree, "Sustain", sustainSlider);

    addAndMakeVisible(sustainSlider);

}

SynthFrameworkAudioProcessorEditor::~SynthFrameworkAudioProcessorEditor()
{
}

//==============================================================================
void SynthFrameworkAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    
}

void SynthFrameworkAudioProcessorEditor::resized()
{
    attackSlider.setBounds(10, 10, 40, 100);
    decaySlider.setBounds(60, 10, 40, 100);
    sustainSlider.setBounds(120, 10, 40, 100);
    releaseSlider.setBounds(160, 10, 40, 100);
}

void sliderValueChanged(juce::Slider* slider)
{

}
