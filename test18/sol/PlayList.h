
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
    PlayList(string name):Item(name){}

    PlayList& operator+=(Item* item){
        items.push_back(item);
        return *this;
    }

    private:

    void buildListOfSongs(PlayList* pl,vector<string> & deepListOfSongs){
		for(Item* i : pl->items){
			if(typeid(*i)==typeid(Song))
				deepListOfSongs.push_back(i->name);
			else{
				PlayList* pld = dynamic_cast<PlayList*>(i);
				if(pld){
					buildListOfSongs(pld,deepListOfSongs);
				}
			}
		}
	}

    public:
    vector<string>::iterator begin(){
    	buildListOfSongs(this,deepListOfSongs);
    	return deepListOfSongs.begin();
    }

    vector<string>::iterator end(){
    	return deepListOfSongs.end();
    }

};

#endif /* SRC_PLAYLIST_H_ */
