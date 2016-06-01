#ifndef SOMTD_MOVABLE_UNIT_H
#define SOMTD_MOVABLE_UNIT_H

#include <ijengine/game_object.h>
#include <ijengine/game_events_listener.h>
#include <ijengine/texture.h>
#include <string>
#include <memory>
#include <queue>

namespace SoMTD {

    class MovableUnit : public ijengine::GameObject, public ijengine::GameEventsListener {
    public:
        MovableUnit(std::pair<int, int> s_pos, std::pair<int, int> e_pos, std::string texture_path);
        ~MovableUnit();
        bool enemy() const;
        void spawn();
        bool active() const;
        void move(int x, int y);
        void add_instruction(int instruction_type, int paramA, int paramB);

    protected:
        void draw_self(ijengine::Canvas*, unsigned, unsigned);
        void draw_self_after(ijengine::Canvas*, unsigned, unsigned);
        bool on_event(const ijengine::GameEvent& event);
        void update_self(unsigned, unsigned);

    private:
        bool m_enemy;
        std::pair<int, int> end_position;
        std::pair<int, int> start_position;
        std::pair<int, int> grid_position;
        std::shared_ptr<ijengine::Texture> m_texture;
        std::pair<int, int> desired_place;
        bool m_active;
        bool m_moving = false;
        int m_x;
        int m_y;
        std::queue< std::pair<int, int> > instructions_queue;
    };
}

#endif
