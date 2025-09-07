#pragma once
#include <stdexcept>
#include <string>

class Exception
{
protected:
	int code = 0;
	std::string message = "";

public:
	Exception(int code, const std::string& message)
		: code(code), message(message) {
	}
	virtual ~Exception() = default;

	inline int get_code() const { return this->code; }
	inline const std::string& get_message() const { return this->message; }
};

template <int exception_code>
class Derived_Exception : public Exception
{
public:
	Derived_Exception(const std::string& message)
		: Exception(exception_code, message) {
	}

	virtual ~Derived_Exception() override = default;
};

#define DEFINE_EXCEPTION(exception_name, exception_code) using exception_name = Derived_Exception<exception_code>

DEFINE_EXCEPTION(Wrong_Angajat_Type, 1001);
DEFINE_EXCEPTION(Wrong_Autospeciala_Type, 1002);
DEFINE_EXCEPTION(Wrong_Urgenta_Type, 1003);