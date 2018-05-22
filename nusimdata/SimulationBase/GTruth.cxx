////////////////////////////////////////////////////////////////////////
/// \file  GTruth.h
/// \Class to hold the additional information needed to recreate a genie::EventRecord
/// \author  nathan.mayer@tufts.edu
////////////////////////////////////////////////////////////////////////

/// This class stores/retrieves the additional information needed (and not in MCTruth) to recreate a genie::EventRecord
/// for genie based event reweighting.

#include "nusimdata/SimulationBase/GTruth.h"

#include <vector>
#include <iostream>
#include <string>
#include <sstream> // for ostringstream
#include <iomanip>

namespace simb {

  //---------------------------------------------------------------
  GTruth::GTruth()
    : fGint(-1)
    , fGscatter(-1)
    , fweight(0)
    , fprobability(0)
    , fXsec(0)
    , fDiffXsec(0)
    , fNumPiPlus(-1)
    , fNumPiMinus(-1)
    , fNumPi0(-1)
    , fNumProton(-1)
    , fNumNeutron(-1)
    , fIsCharm(false)
    , fResNum(-1)
    , fgQ2(kUndefinedValue)
    , fgq2(kUndefinedValue)
    , fgW(kUndefinedValue)
    , fgT(kUndefinedValue)
    , fgX(kUndefinedValue)
    , fgY(kUndefinedValue)
    , fIsSeaQuark(false)
    , ftgtZ(0)
    , ftgtA(0)
    , ftgtPDG(0)
    , fProbePDG(-1)
  {
    fFShadSystP4.SetXYZT(0, 0, 0, 0);
    fHitNucP4.SetXYZT(0, 0, 0, 0);
    fProbeP4.SetXYZT(0, 0, 0, 0);
    fVertex.SetXYZT(0, 0, 0, 0);
  }

  namespace gtruthaux {
    std::string stringifyTLorentzVector(const TLorentzVector& tv4) {
      std::ostringstream s;
      s << "[ "
        << std::setw(11) << tv4.X() << " "
        << std::setw(11) << tv4.Y() << " "
        << std::setw(11) << tv4.Z() << " "
        << std::setw(11) << tv4.T() << " ]";
      return s.str();
    }
  }
  //......................................................................
  std::ostream&  operator<< (std::ostream& output, const simb::GTruth &gtruth)
  {
    output
      << "GTruth:" << std::endl
      //  123456789012
      << "  Gint      " << std::setw(11) << gtruth.fGint         << " "
      << "  Gscatter  " << std::setw(11) << gtruth.fGscatter     << std::endl
      << "  weight    " << std::setw(11) << gtruth.fweight       << " "
      << "  prob      " << std::setw(11) << gtruth.fprobability  << std::endl
      << "  Xsec      " << std::setw(11) << gtruth.fXsec         << " "
      << "  DiffXsec  " << std::setw(11) << gtruth.fDiffXsec     << std::endl
      << "  Npi(+,-,0)" << std::setw(4)  << gtruth.fNumPiPlus    << " "
                        << std::setw(4)  << gtruth.fNumPiMinus   << " "
                        << std::setw(4)  << gtruth.fNumPi0       << " "
      << "  Np Nn     " << std::setw(4)  << gtruth.fNumProton    << " "
                        << std::setw(4)  << gtruth.fNumNeutron   << std::endl
      << "  IsCharm   " << std::setw(4)  << ((gtruth.fIsCharm)?"yes":"no")  << " "
      << "  ResNum    " << std::setw(4)  << gtruth.fResNum       << std::endl
      << "  Q2 q2     " << std::setw(11) << gtruth.fgQ2          << " "
                        << std::setw(11) << gtruth.fgq2          << std::endl
      << "  W  T      " << std::setw(11) << gtruth.fgW           << " "
                        << std::setw(11) << gtruth.fgT           << std::endl
      << "  X  Y      " << std::setw(11) << gtruth.fgX           << " "
                        << std::setw(11) << gtruth.fgY           << std::endl
      << " IsSeaQuark " << std::setw(4)  << ((gtruth.fIsSeaQuark)?"yes":"no") << std::endl
      << " Z A PDG    " << std::setw(4)  << gtruth.ftgtZ         << " "
                        << std::setw(4)  << gtruth.ftgtA         << " "
                        << std::setw(11) << gtruth.ftgtPDG       << " "
      << " probe      " << std::setw(11) << gtruth.fProbePDG     << std::endl
      << " FShadSyst  " << gtruthaux::stringifyTLorentzVector(gtruth.fFShadSystP4) << std::endl
      << " HitNucP4   " << gtruthaux::stringifyTLorentzVector(gtruth.fHitNucP4) << std::endl
      << " ProbeP4    " << gtruthaux::stringifyTLorentzVector(gtruth.fProbeP4) << std::endl
      << " Vertex     " << gtruthaux::stringifyTLorentzVector(gtruth.fVertex)  << std::endl;

    return output;
  }

} // namespace simb
