////////////////////////////////////////////////////////////////////////
/// \file  GTruth.h
/// \Class to hold the additional information needed to recreate a genie::EventRecord
/// \author  nathan.mayer@tufts.edu
////////////////////////////////////////////////////////////////////////

/// This class stores/retrieves the additional information needed
/// (and not in MCTruth) to recreate a genie::EventRecord
/// for genie based event reweighting.

#ifndef SIMB_GTRUTH_H
#define SIMB_GTRUTH_H

#include <iostream>
#include <TLorentzVector.h>

namespace simb {

  class GTruth {

  public:
    GTruth();

    // Interactions info
    int            fGint;         ///< interaction code
    int            fGscatter;     ///< neutrino scattering code

    // Event info
    double         fweight;       ///< event interaction weight (genie internal)
    double         fprobability;  ///< interaction probability
    double         fXsec;         ///< cross section of interaction
    double         fDiffXsec;     ///< differential cross section of interaction

    // genie::XclsTag info
    int            fNumPiPlus;    ///< number of pi pluses after reaction, before FSI
    int            fNumPiMinus;   ///< number of pi minuses after reaction, before FSI
    int            fNumPi0;       ///< number of pi0 after reaction, before FSI
    int            fNumProton;    ///< number of protons after reaction, before FSI
    int            fNumNeutron;   ///< number of neutrons after reaction, before FSI
    bool           fIsCharm;      ///< did the interaction produce a charmed hadron?
    int            fResNum;       ///< resonance number

    // Kinematics info
    ///< these are for the internal (on shell) genie kinematics
    double         fgQ2;
    double         fgq2;
    double         fgW;
    double         fgT;
    double         fgX;
    double         fgY;
    TLorentzVector fFShadSystP4;

    // Target info
    bool           fIsSeaQuark;
    TLorentzVector fHitNucP4;
    int            ftgtZ;
    int            ftgtA;
    int            ftgtPDG;       ///< PDG of Target Nucleus, nucleon only if free

    // Initial State info
    int            fProbePDG;
    TLorentzVector fProbeP4;
    TLorentzVector fVertex;

    // Flag for values that might not have been set
    static constexpr double kUndefinedValue = -99999;

  public:
    friend std::ostream& operator<< (std::ostream& output, const simb::GTruth &gtruth);

  };

} // end simb namespace

#endif // SIMB_GTRUTH_H
