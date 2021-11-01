
find_package(ROOT COMPONENTS Tree RIO Core EG REQUIRED)

cet_make_library(SOURCE GTruth.cxx  MCFlux.cxx  MCNeutrino.cxx
                        MCParticle.cxx  MCTrajectory.cxx  MCTruth.cxx
               LIBRARIES PUBLIC
               canvas::canvas
               fhiclcpp::fhiclcpp
               dk2nu::Tree  # additional data objects assoc w/ MCTruth
               cetlib::cetlib
               cetlib_except::cetlib_except
               ROOT::Core
               ROOT::RIO
               ROOT::Tree
               ROOT::EG # EG needed for TParticleDB
               )

art_dictionary( DICTIONARY_LIBRARIES nusimdata::SimulationBase )

install_headers()
install_fhicl()
install_source()
