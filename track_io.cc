#include <track_io.h>
#include <tinyxml2.h>

namespace track_library {
namespace io {

bool populateTrackFromFile(TrackModel &model, const std::string &path)
{
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLElement * root;
    tinyxml2::XMLElement * tile;

    if (doc.LoadFile(path.c_str()) != tinyxml2::XML_NO_ERROR)
        return false;
    root = doc.RootElement();
    if (std::string(root->Name()) != std::string("track"))
        return false;

    model.setHeight(root->IntAttribute("height"));
    model.setWidth(root->IntAttribute("width"));

    tile = root->FirstChild()->ToElement();
    do
    {
        model.addTile(Tile(static_cast<Tile::Type>(tile->IntAttribute("type")),
                           tile->IntAttribute("x"),
                           tile->IntAttribute("y"),
                           tile->IntAttribute("rotation")));
    }
    while ((tile = tile->NextSiblingElement()));

    return true;
}

bool saveTrackToFile(const TrackModel &model, const std::string &path)
{
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLElement * root = doc.NewElement("track");
    tinyxml2::XMLElement * tile;

    doc.InsertEndChild(root);
    root->SetAttribute("width", model.width());
    root->SetAttribute("height", model.height());

    for (const Tile & t : model.tiles())
    {
        tile = doc.NewElement("tile");
        tile->SetAttribute("type", t.type());
        tile->SetAttribute("x", t.x());
        tile->SetAttribute("y", t.y());
        tile->SetAttribute("rotation", t.rotation());
        root->InsertEndChild(tile);
    }

    if (doc.SaveFile(path.c_str()) == tinyxml2::XML_NO_ERROR)
        return true;
    doc.PrintError();
    return false;
}

}
}
