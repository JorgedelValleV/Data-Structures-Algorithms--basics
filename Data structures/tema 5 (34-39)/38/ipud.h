#ifndef CARNET_PUNTOS_H
#define CANRET_PUNTOS_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include <vector>
#include <unordered_map>
#include <set>
#include<list>
using namespace std;
#define clave first
#define valor second
using song = std::string;
using artist = std::string;
using duracion = int;
class autoescuela {
private:
	unordered_map<song, pair<artist,duracion>> musica;
	set<song> playlist;
	set<pair<int,song>> recientes;
public:
	void addSong(song const& s,artist const& a, duracion const & d) {// O(1) 
		if(!musica.insert({ s,{a,d} }).second)throw std::domain_error("La cancion " + s + " ya existe");
	}
	void addToPlaylist(song const& s) {// O(1) 
		if(playlist.count(s)>0)throw std::domain_error("La cancion " + s + " ya esta en la playlist");;
		playlist.insert(s);
	}
	song current() {// O(1) 
		if (playlist.empty())throw std::domain_error("Playlist vacia");
		else return playlist.front().first;
	}
	song play() {// O(1) 
		if (!playlist.empty()) {
			song s = playlist.front().first;
			recientes.push_front(playlist.front().first);
			playlist.pop_front();
			return s;
		}
		else return "";
	}	
	int totalTime() {// O(1) 
		int res = 0;
		if (playlist.empty())return res;
		else {
			for (auto const & par : playlist)res += par.second;
		}
		return res;
	}
	vector<song> recent(int n) {// O(1) 
		vector<song> ult;
		for (auto it = recientes.cbegin(); it != recientes.cend() && n>0; ++it) {
			ult.push_back(it->second);
			--n;
		}
		return ult;
	}
	void deleteSong(song const& s) {
		musica.erase(s);
		playlist.erase(s);
		recientes.erase(s);
	}
};

#endif //CARNET_PUNTOS_H