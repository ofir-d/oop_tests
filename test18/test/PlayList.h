
#ifndef SRC_PLAYLIST_H_
#define SRC_PLAYLIST_H_

#include <vector>
#include <typeinfo>
#include "Q1.h"
using namespace std;


class PlayList : public Item{
	vector<Item*> items;
	vector<string> deepListOfSongs;
public:
	PlayList(const char *name): Item(name) {}
	const PlayList& operator+=(Item* item)
	{
		items.push_back(item);
		return *this;
	}

	void addSongs(vector<Item *>::iterator items_it)
	{
		if (items_it == items.end())
		{
			return;
		}
		Song* songConverted = dynamic_cast<Song*>(*items_it);
		if (songConverted)
		{
			deepListOfSongs.push_back(songConverted->name);
			addSongs(++items_it);
			return;
		}
		PlayList* pConverted = dynamic_cast<PlayList*>(*items_it);
		if (pConverted)
		{
			pConverted->deepListOfSongs.clear();
			pConverted->addSongs(pConverted->items.begin());
			for (auto i = pConverted->deepListOfSongs.begin(); i < pConverted->deepListOfSongs.end(); i++)
			{
				deepListOfSongs.push_back((*i));
			};
		}
		addSongs(++items_it);

	}

	vector<string>::iterator begin()
	{
		deepListOfSongs.clear();
		addSongs(items.begin());
		return deepListOfSongs.begin();
	}
	vector<string>::iterator end()
	{
		return deepListOfSongs.end();
	}
};

#endif /* SRC_PLAYLIST_H_ */
