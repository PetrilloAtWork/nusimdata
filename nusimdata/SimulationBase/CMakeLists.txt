
find_package(Dk2nuData REQUIRED)
find_package(ROOT COMPONENTS Tree RIO Core EG REQUIRED)

cet_make( LIBRARIES
               canvas::canvas
               fhiclcpp::fhiclcpp
               dk2nu::dk2nuTree  # additional data objects assoc w/ MCTruth
               cetlib::cetlib
               cetlib_except::cetlib_except
               ROOT::Core
               ROOT::RIO
               ROOT::Tree
               ROOT::EG # EG needed for TParticleDB
          NO_DICTIONARY )

art_dictionary( DICTIONARY_LIBRARIES nusimdata::SimulationBase )

install_headers()
install_fhicl()
install_source()
