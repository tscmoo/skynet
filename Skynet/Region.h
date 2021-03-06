#pragma once
#include <memory>
#include "Interface.h"

class ChokepointClass;
typedef std::shared_ptr<ChokepointClass> Chokepoint;
typedef std::weak_ptr<ChokepointClass> WeakChokepoint;

class BaseClass;
typedef std::shared_ptr<BaseClass> Base;

class RegionClass
{
public:
	RegionClass(Position center, int clearance);

	std::set<Chokepoint> getChokepoints() const;

	void addChokepoint(Chokepoint chokepoint);
	void addChokepointTile(Chokepoint chokepoint, TilePosition tile);

	const std::set<TilePosition> &getChokepointTiles() { return mChokePointTiles; }

	void addBase(Base base) { mBases.insert(base); }
	const std::set<Base> &getBases() const { return mBases; }

	const Position &getCenter() const { return mCenter; }
	int getClearance() const { return mClearance; }

	bool isConnected(std::shared_ptr<RegionClass> region) const;

	void setSize(int size) { mSize = size; }
	int getSize() const { return mSize; }

	void draw(BWAPI::Color color);

	void removeChokepoint(Chokepoint chokepoint);

private:
	Position mCenter;
	int mClearance;
	int mSize;

	std::set<Chokepoint> mChokepoints;
	std::map<Chokepoint, TilePosition> mChokePointToTiles;
	std::set<TilePosition> mChokePointTiles;

	std::set<Base> mBases;
};

typedef std::shared_ptr<RegionClass> Region;
typedef std::weak_ptr<RegionClass> WeakRegion;