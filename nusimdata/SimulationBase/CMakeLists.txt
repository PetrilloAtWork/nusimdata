
cet_find_library( DK2NU_TREE NAMES dk2nuTree PATHS ENV DK2NUDATA_LIB NO_DEFAULT_PATH )
include_directories( $ENV{DK2NUDATA_INC} )

# ROOT_BASIC_LIB_LIST is:
#   Core RIO Net Imt Hist Graf Graf3d Gpad Tree Rint Postscript
#   Matrix Physics MathCore Thread

set( SIMB_LIBS
               canvas::canvas
               fhiclcpp
               DK2NU_TREE  # additional data objects assoc w/ MCTruth
               cetlib::cetlib
               cetlib_except::cetlib_except
               ${ROOT_BASIC_LIB_LIST}
               ROOT::EG )  # EG needed for TParticleDB

cet_make( LIBRARIES ${SIMB_LIBS}
          NO_DICTIONARY )

art_dictionary( DICTIONARY_LIBRARIES nusimdata::SimulationBase )

install_headers()
install_fhicl()
install_source()
