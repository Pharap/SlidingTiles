#pragma once

#include <stddef.h>

#include <Arduboy2.h>

struct Particle
{

};

template<size_t maxParticlesValue>
class ParticleSystem
{
public:
	static constexpr size_t maxParticles = maxParticlesValue;

private:

};