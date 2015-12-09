/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Parameters.h"


//==============================================================================
/**
*/
class AudioProcessorValueTreeStateDemoAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    AudioProcessorValueTreeStateDemoAudioProcessor();
    ~AudioProcessorValueTreeStateDemoAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    const String getInputChannelName (int channelIndex) const override;
    const String getOutputChannelName (int channelIndex) const override;
    bool isInputChannelStereoPair (int index) const override;
    bool isOutputChannelStereoPair (int index) const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool silenceInProducesSilenceOut() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    void reset() override;
    
    AudioProcessorValueTreeState parameters;

private:
    //==============================================================================
    
    UndoManager undoManager;
    
    ScopedPointer<NormalisableRange<float>> sampleRateRange;
    double lastSampleRate;
    float filterFreq(float hz);
    
    // mda's vars with their ambigious names...
    float fi2, fo2, clp, lin, lin2, g1, g2, g3, mode;
    float buf0, buf1, buf2, buf3, buf4, buf5, buf6, buf7, buf8, buf9;
    int tn, tcount;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioProcessorValueTreeStateDemoAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
