#include "NotFound.h"
#include <string>
#include <exception>

NotFound::NotFound(const std::string& message)
{
	m_message = message;
}

NotFound::~NotFound() {}

std::string NotFound::getMessage() const
{
	return m_message;
}