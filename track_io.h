#ifndef TRACK_IO_H
#define TRACK_IO_H

#include <string>
#include <track_model.h>

namespace track_library {
namespace io {

bool TRACK_EXPORT populateTrackFromFile(TrackModel & model, const std::string & path);
bool TRACK_EXPORT saveTrackToFile(const TrackModel & model, const std::string & path);

}
}
#endif
