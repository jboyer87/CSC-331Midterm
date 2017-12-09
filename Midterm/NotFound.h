#pragma once

#include <string>
#include <exception>

class NotFound : std::exception
{
public:
	NotFound(const std::string& message);

	~NotFound();

	std::string getMessage() const;

private:
	std::string m_message;
};