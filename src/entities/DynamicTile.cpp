#include "entities/DynamicTile.h"
#include "entities/Tileset.h"
#include "entities/TilePattern.h"

/**
 * Creates a new dynamic tile on the map.
 * @param name a name to identify this tile
 * @param tile_pattern the tile pattern in the tileset 
 * @param layer layer of the tile
 * @param x x position of the tile on the map
 * @param y y position of the tile on the map
 * @param width width of the tile (the pattern can be repeated)
 * @param height height of the tile (the pattern can be repeated)
 * @param enabled true to make the tile active on the map
 */
DynamicTile::DynamicTile(string name, TilePattern *tile_pattern,
			 Layer layer, int x, int y,
			 int width, int height, bool enabled):
  MapEntity(name, 0, layer, x, y, width, height),
  tile_pattern(tile_pattern), enabled(enabled) {

}

/**
 * Destructor.
 */
DynamicTile::~DynamicTile(void) {

}

/**
 * Returns the type of entity.
 * @return the type of entity
 */
MapEntity::EntityType DynamicTile::get_type(void) {
  return DYNAMIC_TILE;
}

/**
 * Returns whether this tile is an obstacle for the specified entity.
 * @param other an entity
 * @return true if this tile is an obstacle for the entity
 */
bool DynamicTile::is_obstacle_for(MapEntity *other) {
  return enabled && tile_pattern->get_obstacle() >= OBSTACLE;
}

/**
 * Displays the tile on the map.
 */
void DynamicTile::display_on_map(void) {
  if (enabled) {
    tile_pattern->display_on_map(map, position_in_map);
  }
}
