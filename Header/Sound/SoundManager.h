#pragma once
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;

namespace Sounds
{
    enum class SoundType
    {
        BALL_BOUNCE
    };

    class SoundManager
    {
    private:
        static Sound soundEffect;
        static SoundBuffer ballBounce;

        static sf::Music backgroundMusic;
        static const string bgmPath;
        static float backgroundMusicVolume;

        static const string ballBouncePath;
        
        static void LoadSoundFromFile();

    public:
        static void Initialize();
        static void PlaySoundEffect(SoundType soundType);
        static void PlayBackgroundMusic();
    };
}