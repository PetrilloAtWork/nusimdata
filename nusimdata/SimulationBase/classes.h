//
// Build a dictionary.
//
// $Id: classes.h,v 1.9 2012-10-29 16:42:11 brebel Exp $
// $Author: brebel $
// $Date: 2012-10-29 16:42:11 $
//
// Original author Rob Kutschke, modified by klg, rhatcher

#include "canvas/Persistency/Common/Wrapper.h"
#include "canvas/Persistency/Common/Assns.h"

// nusimdata includes
#include "nusimdata/SimulationBase/MCTruth.h"
#include "nusimdata/SimulationBase/MCTrajectory.h"
#include "nusimdata/SimulationBase/MCParticle.h"
#include "nusimdata/SimulationBase/MCNeutrino.h"
#include "nusimdata/SimulationBase/MCFlux.h"
#include "nusimdata/SimulationBase/GTruth.h"
#include <TLorentzVector.h>

// MCTruth/MCFlux will be associated with these
#include "dk2nu/tree/dk2nu.h"
#include "dk2nu/tree/NuChoice.h"

