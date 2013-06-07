#ifndef CONSOLE_H
#define CONSOLE_H

#include "ConsoleMessageType.h"
#include <string>
#include <sstream>

namespace thewizardplusplus {
namespace utils {

class Console {
public:
	static Console information(void);
	static Console error(void);

	Console(ConsoleMessageType::Types message_type);
	~Console(void);
	template<typename ValueType>
	Console& operator<<(ValueType value);

private:
	ConsoleMessageType::Types message_type;
	std::string               message_text;
};

template<typename ValueType>
Console& Console::operator<<(ValueType value) {
	std::ostringstream out;
	out << value;
	this->message_text += out.str();

	return *this;
}

}
}
#endif