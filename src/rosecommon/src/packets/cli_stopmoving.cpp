#include "cli_stopmoving.h"

namespace RoseCommon {

CliStopMoving::CliStopMoving() : CRosePacket(ePacketType::PAKCS_STOP_MOVING) {}

CliStopMoving::CliStopMoving(uint8_t buffer[MAX_PACKET_SIZE]) : CRosePacket(buffer) {
	if (type() != ePacketType::PAKCS_STOP_MOVING)
		throw std::runtime_error("Not the right packet!");
	*this >> x_;
	*this >> y_;
	*this >> z_;
}

CliStopMoving::CliStopMoving(float x, float y, int16_t z) : CRosePacket(ePacketType::PAKCS_STOP_MOVING), x_(x), y_(y), z_(z) {}

float CliStopMoving::x() const {
	return x_;
}

float CliStopMoving::y() const {
	return y_;
}

int16_t CliStopMoving::z() const {
	return z_;
}


void CliStopMoving::pack() {
	*this << x_;
	*this << y_;
	*this << z_;
}

}