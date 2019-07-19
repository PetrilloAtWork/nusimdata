////////////////////////////////////////////////////////////////////////
/// \file  MCGeneratorInfo.cxx
/// \brief Info on the generator
///
/// \author  J. Wolcott <jwolcott@fnal.gov>
////////////////////////////////////////////////////////////////////////

#ifndef SIMB_MCGENERATORINFO_H
#define SIMB_MCGENERATORINFO_H

#include <string>
#include <unordered_map>

namespace simb
{

  /// generator used to produce event, if applicable
  typedef enum _ev_generator{
    kUnknown,
    kCRY,
    kGEANT,
    kGENIE,
    kGIBUU,
    kNEUT,
    kNuWro,
  } Generator_t;

  struct MCGeneratorInfo
  {
    simb::Generator_t                            fGenerator;        ///< event generator that generated this event
    std::string                                  fGeneratorVersion  ///< event generator version
    std::unordered_map<std::string, std::string> fGeneratorConfig   ///< free-form field that can be used to keep track of generator configuration (e.g. GENIE tune)

    MCGeneratorInfo(Generator_t gen = Generator_t::kUnknown,
                    const std::string ver = "",
                    const std::unordered_map<std::string, std::string> config = {})
      : fGenerator(gen), fGeneratorVersion(ver), fGeneratorConfig(config)
    {}
  };
}

#endif //SIMB_MCGENERATORINFO_H
