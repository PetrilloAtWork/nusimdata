
cet_find_library( DK2NU_TREE NAMES dk2nuTree PATHS ENV DK2NUDATA_LIB NO_DEFAULT_PATH ) ### MIGRATE-ACTION-RECOMMENDED: use of ENV ... may be UPS-dependent ### MIGRATE-ACTION-RECOMMENDED: use cet_find_package() with target semantics for linking
include_directories( $ENV{DK2NUDATA_INC} ) ### MIGRATE-ACTION-RECOMMENDED: use target_link_directories() with target semantics

# ROOT_BASIC_LIB_LIST is:
#   Core RIO Net Imt Hist Graf Graf3d Gpad Tree Rint Postscript
#   Matrix Physics MathCore Thread
find_package(ROOT COMPONENTS Tree RIO Core EG REQUIRED)

cet_make( LIBRARIES
               canvas::canvas
               fhiclcpp
               DK2NU_TREE  # additional data objects assoc w/ MCTruth
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
