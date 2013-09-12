
#pragma once
#include "stdafx.h"
#if defined(__vxworks)


#elif defined(SIMSTER_BUILD)

#include "CVode.h"


/*Simster factory*/
extern "C" void BOOST_EXTENSION_EXPORT_DECL extension_export_cvode(boost::extensions::factory_map & fm)
{
    fm.get<ISolver,int,IMixedSystem*, ISolverSettings*>()[1].set<Cvode>();
    //fm.get<ISolverSettings,int, IGlobalSettings* >()[2].set<CVodeSettings>();
}

#elif defined(OMC_BUILD)

#include "CVode.h"
#include "CVodeSettings.h"

    /* OMC factory */
    using boost::extensions::factory;

    BOOST_EXTENSION_TYPE_MAP_FUNCTION {
    types.get<std::map<std::string, factory<ISolver,IMixedSystem*, ISolverSettings*> > >()
    ["cvodeSolver"].set<Cvode>();
    types.get<std::map<std::string, factory<ISolverSettings, IGlobalSettings* > > >()
    ["cvodeSettings"].set<CVodeSettings>();
    }

#else
error "operating system not supported"
#endif



   