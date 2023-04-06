/*
 * Copyright (c) 2021 Realtek, LLC.
 * All rights reserved.
 *
 * Licensed under the Realtek License, Version 1.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License from Realtek
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef AMEBA_FWK_MEDIA_PLAYBACK_UTILS_MEDIA_UTILS_MESSAGE_LOOPER_MANAGER_H
#define AMEBA_FWK_MEDIA_PLAYBACK_UTILS_MEDIA_UTILS_MESSAGE_LOOPER_MANAGER_H

#include <vector>
#include <map>
#include <string>

#include "media/utils/message_looper.h"
#include "media/utils/message_handler.h"

namespace ameba::media
{

class MessageLooperManager
{
public:
	MessageLooperManager();

	MessageLooper::HandlerID RegisterHandler(
		const sptr<MessageLooper> &looper, const sptr<MessageHandler> &handler);

	void UnregisterHandler(MessageLooper::HandlerID handler_id);
	void UnregisterStaleHandlers();

	void Dump(int fd, const std::vector<std::u16string> &args);

private:
	struct HandlerInfo {
		wptr<MessageLooper> looper;
		wptr<MessageHandler> handler;
	};

	Mutex lock_;
	std::map<MessageLooper::HandlerID, HandlerInfo> handlers_;
	MessageLooper::HandlerID unique_handle_id_;

	DISALLOW_COPY_AND_MOVE(MessageLooperManager);
};

}  // namespace ameba::media

#endif  // AMEBA_FWK_MEDIA_PLAYBACK_UTILS_MEDIA_UTILS_MESSAGE_LOOPER_MANAGER_H