/*
  ==============================================================================

    FilterToolComponent.h
    Created: 24 Jun 2025 1:48:12pm
    Author:  rasmu

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SoloFilterProcessing.h"
#include "ApplicationColours.h"

//==============================================================================
/*
*/
class FilterToolComponent  : public juce::Component
{
public:

    enum FilterButton
    {
        SubFilterButton,
        LowMidFilterButton,
        HighMidFilterButton,
        AirFilterButton
	};

    FilterToolComponent(SoloFilterType& sharedFilterType);
    ~FilterToolComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;


    void updateFilterButtons();

private:
	void changeButtonColour(FilterButton filterType, juce::Colour colour);

    juce::Component filterButtonContainer;

	SoloFilterType& soloFilter;

    juce::TextButton subFilterButton;
	juce::TextButton lowMidFilterButton;
	juce::TextButton highMidFilterButton;
	juce::TextButton airFilterButton;



    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterToolComponent)
};
