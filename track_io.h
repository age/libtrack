#ifndef TRACK_IO_H
#define TRACK_IO_H

#include <string>
#include <tinyxml2.h>
#include <track_model.h>

namespace track_library {
namespace io {

bool populateTrackFromFile(TrackModel & model, const std::string & path);
bool saveTrackToFile(const TrackModel & model, const std::string & path);

}
}
#endif
