
find_library( DK2NU_TREE NAMES dk2nuTree PATHS DK2NUDATA_LIB)
include_directories( ${DK2NUDATA_INC} )
include_directories( ${Boost_INCLUDE_DIR} )

set( SIMB_LIBS
               canvas
               fhiclcpp
               ${DK2NU_TREE}  # additional data objects assoc w/ MCTruth
               cetlib
               cetlib_except
               ${ROOT_LIBRARIES}
               ROOT::EG )  # EG needed for TParticleDB

cet_make( LIBRARIES ${SIMB_LIBS}
          NO_DICTIONARY )

art_dictionary( DICTIONARY_LIBRARIES nusimdata_SimulationBase )

install_headers()
install_fhicl()
install_source()
