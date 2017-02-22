set( SIMB_LIBS 
               canvas
               fhiclcpp
               cetlib
	       cetlib_except
               ${ROOT_EG}
               ${ROOT_CORE}
               ${ROOT_CINT}
               ${ROOT_RIO}
               ${ROOT_NET}
               ${ROOT_HIST}
               ${ROOT_GRAF}
               ${ROOT_GRAF3D}
               ${ROOT_GPAD}
               ${ROOT_TREE}
               ${ROOT_RINT}
               ${ROOT_POSTSCRIPT}
               ${ROOT_MATRIX}
               ${ROOT_PHYSICS}
               ${ROOT_MATHCORE}
               ${ROOT_THREAD} )

cet_make( LIBRARIES ${SIMB_LIBS}
          NO_DICTIONARY )

art_dictionary( DICTIONARY_LIBRARIES nusimdata_SimulationBase )
 
install_headers()
install_fhicl()
install_source()
