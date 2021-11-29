find_package(ROOT COMPONENTS Physics REQUIRED PRIVATE)
cet_test(MCParticle_test USE_BOOST_UNIT
  SOURCE MCParticle_test.cxx
  LIBRARIES PRIVATE nusimdata::SimulationBase cetlib::headers ROOT::Physics
  )

