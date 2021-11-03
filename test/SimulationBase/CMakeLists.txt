find_package(ROOT PRIVATE COMPONENTS Physics REQUIRED)
cet_test(MCParticle_test USE_BOOST_UNIT
  SOURCE MCParticle_test.cxx
  LIBRARIES PRIVATE nusimdata::SimulationBase cetlib::headers ROOT::Physics
  )

