#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(bool is_first) : _is_first{is_first}
{
}

Position ComputerPlayer::get_pos(const ChessBroad &current, Position last)
{
    if (!_is_first)
        _tree.update(last);
    _is_first = false;
    auto pos = _tree.decide();
    _tree.update(pos);
    return pos;
}