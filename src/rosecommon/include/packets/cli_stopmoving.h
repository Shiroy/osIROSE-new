#pragma once

#include "packetfactory.h"
#include "entityComponents.h"


namespace RoseCommon {

REGISTER_RECV_PACKET(ePacketType::PAKCS_STOP_MOVING, CliStopMoving)
class CliStopMoving : public CRosePacket {
	public:
		CliStopMoving();
		CliStopMoving(uint8_t buffer[MAX_PACKET_SIZE]);
		CliStopMoving(float x, float y, int16_t z);

		virtual ~CliStopMoving() = default;

		float x() const;
		float y() const;
		int16_t z() const;

	protected:
		virtual void pack() override;

	private:
		float x_;
		float y_;
		int16_t z_;
};

}