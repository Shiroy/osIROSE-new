#pragma once

#include "packetfactory.h"
#include "entitycomponents.h"


namespace RoseCommon {

REGISTER_SEND_PACKET(ePacketType::PAKWC_SELECT_CHAR_REPLY, SrvSelectCharReply)
class SrvSelectCharReply : public CRosePacket {
	public:
		SrvSelectCharReply();
		SrvSelectCharReply(Entity entity);

		virtual ~SrvSelectCharReply() = default;

		Entity entity() const;

	protected:
		virtual void pack() override;

	private:
		Entity entity_;
};

}