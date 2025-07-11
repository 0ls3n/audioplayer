/*
  ==============================================================================

    TransportToolComponent.cpp
    Created: 22 Jun 2025 8:20:27pm
    Author:  rasmu

  ==============================================================================
*/

#include <JuceHeader.h>
#include "TransportToolComponent.h"

//==============================================================================
TransportToolComponent::TransportToolComponent()
{

    addAndMakeVisible(openButton);
    openButton.setButtonText("Open file");
    openButton.setColour(juce::TextButton::buttonColourId, ApplicationColours().secondary);
    openButton.onClick = [this]()
        {
            if (onOpenButtonClicked) onOpenButtonClicked();
        };

    addAndMakeVisible(referenceButton);
    referenceButton.setButtonText("Reference");
    referenceButton.setColour(juce::TextButton::buttonColourId, ApplicationColours().secondary);
    referenceButton.setEnabled(true);
    referenceButton.onClick = [this]()
        {
            if (onReferenceButtonClicked) onReferenceButtonClicked();
        };
}

TransportToolComponent::~TransportToolComponent()
{
}

void TransportToolComponent::paint (juce::Graphics& g)
{
    g.fillAll (ApplicationColours().toolbar);
}

void TransportToolComponent::resized()
{
    auto area = getLocalBounds();

    auto buttonWidth = 100;
    auto buttonMargin = 10;

	openButton.setBounds(area.removeFromLeft(buttonWidth).reduced(buttonMargin));
	referenceButton.setBounds(area.removeFromLeft(buttonWidth).reduced(buttonMargin));

}

void TransportToolComponent::setButtonEnabled(ButtonId buttonId, bool enabled)
{
    switch (buttonId)
    {
    case ButtonId::OpenButton:
        openButton.setEnabled(enabled);
        break;
    case ButtonId::ReferenceButton:
        referenceButton.setEnabled(enabled);
        break;
    }
}

void TransportToolComponent::setButtonText(ButtonId buttonId, const juce::String& text)
{
    switch (buttonId)
    {
    case ButtonId::OpenButton:
        openButton.setButtonText(text);
        break;
    case ButtonId::ReferenceButton:
        referenceButton.setButtonText(text);
        break;
	}
}

void TransportToolComponent::setButtonColour(ButtonId buttonId, const juce::Colour& colour)
{
    switch (buttonId)
    {
    case ButtonId::OpenButton:
        openButton.setColour(juce::TextButton::buttonColourId, colour);
        break;
    case ButtonId::ReferenceButton:
        referenceButton.setColour(juce::TextButton::buttonColourId, colour);
        break;
	}
}
