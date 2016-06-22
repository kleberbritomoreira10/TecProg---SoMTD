#include <fstream>
#include <vector>
#include "wave.h"

SoMTD::Wave::Wave(unsigned p_id) :
    m_done(false),
    m_started(false),
    m_id(p_id),
    m_spawning(false)
{
}

SoMTD::Wave::~Wave()
{
}

unsigned
SoMTD::Wave::id() const
{
    return m_id;
}

std::vector<int>
SoMTD::Wave::units() const
{
    return m_units;
}

void
SoMTD::Wave::add_unit(int unit_id)
{
    m_units.push_back(unit_id);
}

void
SoMTD::Wave::spawn_unit()
{
    if (m_current_unit_idx+1 >= units().size()) {
        m_spawning = false;
    } else {
        m_current_unit_idx += 1;
    }
}

bool
SoMTD::Wave::done() const
{
    return m_done;
}

void
SoMTD::Wave::update_self(unsigned a1, unsigned a2)
{
}

void
SoMTD::Wave::finish()
{
    m_done = true;
}

int
SoMTD::Wave::current_unit()
{
    return m_current_unit_idx;
}

bool
SoMTD::Wave::started() const
{
    return m_started;
}

void
SoMTD::Wave::start(unsigned now)
{
    m_started_at = now;
    m_started = true;
    m_spawning = true;
    m_current_unit_idx = 0;
}

unsigned
SoMTD::Wave::started_at() const
{
    return m_started_at;
}

bool
SoMTD::Wave::spawning() const
{
    return m_spawning;
}