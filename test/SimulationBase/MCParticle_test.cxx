/**
 * @file   MCParticle_test.cxx
 * @brief  Test for simb::MCParticle data product
 * @author Gianluca Petrillo (petrillo@fnal.gov)
 * @date   November 21, 2017
 *
 * Current checks:
 * * move constructor actially moves (see issue #12067)
 *
 * See http://www.boost.org/libs/test for the Boost test library home page.
 * 
 */

#define BOOST_TEST_MODULE ( mcparticle_test )
#include "cetlib/quiet_unit_test.hpp" // BOOST_AUTO_TEST_CASE()
#include <boost/test/test_tools.hpp> // BOOST_CHECK()
// #include <boost/test/floating_point_comparison.hpp> // BOOST_CHECK_CLOSE()

// nutools libraries
#include "nusimdata/SimulationBase/MCParticle.h"
#include "nusimdata/SimulationBase/MCTrajectory.h"

// ROOT libraries
#include "TLorentzVector.h"

// C/C++ standard libraries
#include <vector>


//------------------------------------------------------------------------------
void MCTrajectoryMoveTest() {
  
  simb::MCTrajectory traj;
  traj.Add(TLorentzVector(), TLorentzVector(), "hadElastic");
  traj.Add(TLorentzVector(), TLorentzVector(), "hadElastic");
  
  // if the object is moved, we'll find the process map data at the same place
  auto const* pProcessMap = traj.TrajectoryProcesses().data();
  
  simb::MCTrajectory movedTraj(std::move(traj));
  
  BOOST_CHECK_EQUAL
    ((void*) movedTraj.TrajectoryProcesses().data(), (void*) pProcessMap);
  BOOST_CHECK_NE((void*) traj.TrajectoryProcesses().data(), (void*) pProcessMap);
  
} // MCTrajectoryMoveTest()

//------------------------------------------------------------------------------
void MCParticleMoveTest() {
  
  simb::MCParticle part;
  part.AddTrajectoryPoint(TLorentzVector(), TLorentzVector(), "hadElastic");
  part.AddTrajectoryPoint(TLorentzVector(), TLorentzVector(), "hadElastic");
  
  // if the object is moved, we'll find the process map data at the same place
  auto const* pProcessMap = part.Trajectory().TrajectoryProcesses().data();
  
  simb::MCParticle movedPart(std::move(part));
  
  BOOST_CHECK_EQUAL(
    (void*) movedPart.Trajectory().TrajectoryProcesses().data(),
    (void*) pProcessMap
    );
  BOOST_CHECK_NE(
    (void*) part.Trajectory().TrajectoryProcesses().data(),
    (void*) pProcessMap
    );
  
  
} // MCParticleMoveTest()

//------------------------------------------------------------------------------
//--- registration of tests
//

BOOST_AUTO_TEST_CASE(MCParticleTestCase) {
  MCTrajectoryMoveTest();
  MCParticleMoveTest();
} // BOOST_AUTO_TEST_CASE(MCParticleTestCase)


//------------------------------------------------------------------------------
