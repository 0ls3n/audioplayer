/*
  ==============================================================================

    TransportToolComponent.h
    Created: 22 Jun 2025 8:20:27pm
    Author:  rasmu

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "ApplicationColours.h"

//==============================================================================
/*
*/
class TransportToolComponent  : public juce::Component
{
public:
    TransportToolComponent();
    ~TransportToolComponent() override;

    enum class ButtonId
    {
        OpenButton,
        ReferenceButton
    };

    void paint (juce::Graphics&) override;
    void resized() override;

    void setButtonEnabled(ButtonId buttonId, bool enabled);
	void setButtonText(ButtonId buttonId, const juce::String& text);
	void setButtonColour(ButtonId buttonId, const juce::Colour& colour);

	std::function<void()> onOpenButtonClicked;
    std::function<void()> onReferenceButtonClicked;

    

private:

    juce::TextButton playButton;
    juce::TextButton stopButton;
    juce::TextButton openButton;
    juce::TextButton referenceButton;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TransportToolComponent)
};


