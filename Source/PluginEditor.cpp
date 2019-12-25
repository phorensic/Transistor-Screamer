/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TransistorScreamerAudioProcessorEditor::TransistorScreamerAudioProcessorEditor (TransistorScreamerAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (600, 200);

    // Map out a reverse range for the volume slider
    auto range = NormalisableRange<double>(0.0, 100.0,
        [](auto rangeStart, auto rangeEnd, auto normalised)
        { return jmap(normalised, rangeEnd, rangeStart); },
        [](auto rangeStart, auto rangeEnd, auto value)
        { return jmap(value, rangeEnd, rangeStart, 0.0, 1.0); });

    range.interval = 1;

    // these define the parameters of our slider object
    audioVolume.setNormalisableRange(range);
    audioVolume.setTextBoxStyle(Slider::NoTextBox, false, 100, 20);

    // listener for the slider
    audioVolume.addListener(this);

    // this function adds the slider to the editor
    addAndMakeVisible(&audioVolume);
}

void TransistorScreamerAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    processor.audioLevel = audioVolume.getValue();
}

TransistorScreamerAudioProcessorEditor::~TransistorScreamerAudioProcessorEditor()
{
}

//==============================================================================
void TransistorScreamerAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Volume", 0, 0, getWidth(), 30, Justification::centred, 1);
}

void TransistorScreamerAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    // sets the position and size of the slider with arguments (x, y, width, height)
    audioVolume.setBounds(40, 30, getWidth() - 60, 20);
}
