#ifndef TRACK_MODEL_H
#define TRACK_MODEL_H

#include <list>

namespace track_library {

class Tile
{
public:
    enum Type { Start, Line, Turn, Hill, Teeth, Saw, Crossing, Invalid };

    Tile(Type type, int x, int y, int rotation);

    Type type() const;
    int x() const;
    int y() const;
    int rotation() const;
private:
    Type m_type;
    int m_x, m_y, m_rotation;
};

class TrackModel
{
public:
    TrackModel(int width = 0, int height = 0);

    const std::list<Tile> & tiles() const;
    bool addTile(const Tile & tile);
    int width() const;
    void setWidth(int w);
    int height() const;
    void setHeight(int h);

    void clear();
private:
    const Tile * tileAt(int x, int y) const;

    int m_width;
    int m_height;
    std::list<Tile> m_tiles;
};

}

#endif
