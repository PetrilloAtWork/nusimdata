
find_package(ROOT PUBLIC COMPONENTS Core Physics RIO Tree REQUIRED)
find_package(ROOT PRIVATE COMPONENTS EG REQUIRED)

cet_make_library(SOURCE GTruth.cxx  MCFlux.cxx  MCNeutrino.cxx
                        MCParticle.cxx  MCTrajectory.cxx  MCTruth.cxx
               LIBRARIES PRIVATE
               canvas::canvas
               ROOT::EG # EG needed for TParticleDB
               PUBLIC
               ROOT::Physics)

art_dictionary(DICTIONARY_LIBRARIES nusimdata::SimulationBase dk2nu::Tree)

install_headers()
install_fhicl()
install_source()
