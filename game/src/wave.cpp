#include <fstream>
#include <vector>
#include "wave.h"

SoMTD::Wave::Wave(unsigned p_id) :
    m_done(false),
    m_started(false),
    m_id(p_id)
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

bool
SoMTD::Wave::done() const
{
    return m_done;
}

void
SoMTD::Wave::update_self(unsigned a1, unsigned a2)
{
    if (a1 > 10000*id())
        m_done = true;
}

bool
SoMTD::Wave::started() const
{
    return m_started;
}

void
SoMTD::Wave::start()
{
    m_started = true;
}
