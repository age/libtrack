#include <track_model.h>

namespace track_library {

Tile::Tile(Tile::Type type, int x, int y, int rotation)
    : m_type (type)
    , m_x (x)
    , m_y (y)
    , m_rotation (rotation)
{
}

Tile::Type Tile::type() const
{
    return m_type;
}

int Tile::x() const
{
    return m_x;
}

int Tile::y() const
{
    return m_y;
}

int Tile::rotation() const
{
    return m_rotation;
}

TrackModel::TrackModel(int width, int height)
    : m_width (width)
    , m_height (height)
{
}

const Tile *TrackModel::tileAt(int x, int y) const
{
    for (const Tile & t : m_tiles)
        if (t.x() == x && t.y() == y)
            return &t;
    return nullptr;
}

const std::list<Tile> &TrackModel::tiles() const
{
    return m_tiles;
}

bool TrackModel::addTile(const Tile & tile)
{
    if (tileAt(tile.x(), tile.y()))
        return false;
    m_tiles.push_back(tile);
    return true;
}

int TrackModel::width() const
{
    return m_width;
}

void TrackModel::setWidth(int w)
{
    m_width = w;
}

int TrackModel::height() const
{
    return m_height;
}

void TrackModel::setHeight(int h)
{
    m_height = h;
}

}
