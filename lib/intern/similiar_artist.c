/***********************************************************
* This file is part of glyr
* + a commnadline tool and library to download various sort of musicrelated metadata.
* + Copyright (C) [2011]  [Christopher Pahl]
* + Hosted at: https://github.com/sahib/glyr
*
* glyr is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* glyr is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with glyr. If not, see <http://www.gnu.org/licenses/>.
**************************************************************/

#include "../core.h"
#include "../stringlib.h"
#include "generic.h"

/*----------------------------------------------------------------*/

bool vdt_similiar(GlyrQuery * settings)
{
    if(settings && settings->artist && settings->artist[0])
    {
        return true;
    }
    glyr_message(2,settings,"Artist is needed to retrieve similar artists.\n");
    return false;
}

/*----------------------------------------------------------------*/

static GList * factory(GlyrQuery * s, GList * list, gboolean * stop_me)
{
    return generic_txt_finalizer(s,list,stop_me,GLYR_TYPE_SIMILIAR_SONG);
}

/*----------------------------------------------------------------*/

/* PlugStruct */
MetaDataFetcher glyrFetcher_similiar_artists =
{
    .name = "similarartists",
    .type = GLYR_GET_SIMILIAR_ARTISTS,
    .validate  = vdt_similiar,
    .full_data = TRUE,
    .init    = NULL,
    .destroy = NULL,
    .finalize = factory
};