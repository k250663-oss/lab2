
#include<iostream>
using namespace std;

class PlaylistManager {
private:
    int** customPlaylists;
    int* playlistCapacities;
    int playlistCount;

public:
    PlaylistManager(int p, int sizes[]) {
        playlistCount = p;

        customPlaylists = new int*[p];
        playlistCapacities = new int[p];

        for(int i = 0; i < p; i++) {
            playlistCapacities[i] = sizes[i];
            customPlaylists[i] = new int[sizes[i]];

            for(int j = 0; j < sizes[i]; j++) {
                customPlaylists[i][j] = 0;
            }
        }
    }

    // Deep copy constructor
    PlaylistManager(const PlaylistManager& other) {
        playlistCount = other.playlistCount;

        customPlaylists = new int*[playlistCount];
        playlistCapacities = new int[playlistCount];

        for(int i = 0; i < playlistCount; i++) {
            playlistCapacities[i] = other.playlistCapacities[i];

            customPlaylists[i] =
                new int[playlistCapacities[i]];

            for(int j = 0; j < playlistCapacities[i]; j++) {
                customPlaylists[i][j] =
                    other.customPlaylists[i][j];
            }
        }
    }

    // Copy assignment operator
    PlaylistManager& operator=(const PlaylistManager& other) {
        if(this == &other) {
            return *this;
        }

        int** temp = new int*[other.playlistCount];
        int* sizes = new int[other.playlistCount];

        for(int i = 0; i < other.playlistCount; i++) {
            sizes[i] = other.playlistCapacities[i];
            temp[i] = new int[sizes[i]];

            for(int j = 0; j < sizes[i]; j++) {
                temp[i][j] = other.customPlaylists[i][j];
            }
        }

        for(int i = 0; i < playlistCount; i++) {
            delete[] customPlaylists[i];
        }

        delete[] customPlaylists;
        delete[] playlistCapacities;

        customPlaylists = temp;
        playlistCapacities = sizes;
        playlistCount = other.playlistCount;

        return *this;
    }

    void setTrack(int p, int t, int id) {
        if(p < 0 || p >= playlistCount ||
           t < 0 || t >= playlistCapacities[p]) {
            cout << "Invalid playlist or track!\n";
            return;
        }

        customPlaylists[p][t] = id;
    }

    void addTrack(int p, int id) {
        if(p < 0 || p >= playlistCount) {
            cout << "Invalid playlist!\n";
            return;
        }

        int oldSize = playlistCapacities[p];
        int* temp = new int[oldSize + 1];

        for(int i = 0; i < oldSize; i++) {
            temp[i] = customPlaylists[p][i];
        }

        temp[oldSize] = id;

        delete[] customPlaylists[p];

        customPlaylists[p] = temp;
        playlistCapacities[p]++;

        cout << "Track added to playlist " << p << endl;
    }

    void playTrack(int p, int t) {
        if(p < 0 || p >= playlistCount) {
            cout << "Invalid playlist!\n";
            return;
        }

        if(t < 0 || t >= playlistCapacities[p]) {
            cout << "Invalid track!\n";
            return;
        }

        cout << "Playing track ID: "
             << customPlaylists[p][t] << endl;
    }

    void display() {
        for(int i = 0; i < playlistCount; i++) {
            cout << "Playlist " << i << ": ";

            for(int j = 0; j < playlistCapacities[i]; j++) {
                cout << customPlaylists[i][j] << " ";
            }

            cout << endl;
        }
    }

    ~PlaylistManager() {
        for(int i = 0; i < playlistCount; i++) {
            delete[] customPlaylists[i];
        }

        delete[] customPlaylists;
        delete[] playlistCapacities;
    }
};

int main() {
    int sizes[3] = {2, 3, 1};

    PlaylistManager original(3, sizes);

    original.setTrack(0, 0, 101);
    original.setTrack(0, 1, 102);
    original.setTrack(1, 0, 201);
    original.setTrack(1, 1, 202);
    original.setTrack(1, 2, 203);
    original.setTrack(2, 0, 301);

    cout << "Original playlists:\n";
    original.display();

    PlaylistManager copy(original);

    copy.addTrack(0, 103);
    copy.setTrack(0, 0, 999);

    cout << "\nCopied playlists:\n";
    copy.display();

    cout << "\nOriginal after modifying copy:\n";
    original.display();

    cout << "\nTesting bounds:\n";
    original.playTrack(1, 2);
    original.playTrack(1, 5);

    return 0;
}
