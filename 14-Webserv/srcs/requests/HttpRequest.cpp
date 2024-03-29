/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpRequest.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:34:48 by mdelwaul          #+#    #+#             */
/*   Updated: 2022/11/08 15:59:25 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <algorithm>
#include <string>

#include "Colors.hpp"
#include "HttpRequest.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

HttpRequest::HttpRequest(Server& serv) : _serv(serv), _method(""), _path(""), _queryString(""), _httpVersion(""), _host(""), _connection(""), _contentType(""), _contentLength(0), _body("")
{
}


HttpRequest::HttpRequest( const HttpRequest & src ): _serv(src._serv)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

HttpRequest::~HttpRequest()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

HttpRequest &				HttpRequest::operator=( HttpRequest const &rhs )
{
	if ( this != &rhs )
	{
		_method = rhs._method;
		_path = rhs._path;
		_queryString = rhs._queryString;
		_httpVersion = rhs._httpVersion;
		_host = rhs._host;
		_connection = rhs._connection;
		_contentType = rhs._contentType;
		_contentLength = rhs._contentLength;
		_body = rhs._body;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, HttpRequest const & i )
{
	o << "Method = " << i.getMethod() << std::endl;
	o << "Path = " << i.getPath() << std::endl;
	o << "Query string = " << i.getQueryString() << std::endl;
	o << "HTTP version = " << i.getHttpVersion() << std::endl;
	o << "Host = " << i.getHost() << std::endl;
	o << "Connection = " << i.getConnection() << std::endl;
	o << "Content type = " << i.getContentType() << std::endl;
	o << "Content lengh = " << i.getContentLength() << std::endl;
	o << "Body = " << i.getBody() << std::endl;


	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	HttpRequest::getMethod() const
{
	return (_method);
}

void		HttpRequest::setMethod(std::string method)
{
	_method = method;
}

std::string	HttpRequest::getPath() const
{
	return (_path);
}

void		HttpRequest::setPath(std::string path)
{
	
	_path = path;
}

std::string	HttpRequest::getQueryString() const
{
	return (_queryString);
}

void		HttpRequest::setQueryString(std::string query)
{
	_queryString = query;
}

std::string	HttpRequest::getHttpVersion() const
{
	return (_httpVersion);
}

void		HttpRequest::setHttpVersion(std::string httpVersion)
{
	_httpVersion = httpVersion;
}

std::string	HttpRequest::getHost() const
{
	return (_host);
}

void		HttpRequest::setHost(std::string host)
{
	_host = host;
}

std::string	HttpRequest::getConnection() const
{
	return (_connection);
}

void		HttpRequest::setConnection(std::string connection)
{
	_connection = connection;
}

std::string	HttpRequest::getContentType() const
{
	return (_contentType);
}

void		HttpRequest::setContentType(std::string contentType)
{
	_contentType = contentType;
}

unsigned int	HttpRequest::getContentLength() const
{
	return (_contentLength);
}

void		HttpRequest::setContentLength(std::string ContentLength)
{
	unsigned int	nb = atol(ContentLength.c_str());

	_contentLength = nb;
}

std::string	HttpRequest::getBody() const
{
	return (_body);
}

void		HttpRequest::setBody(std::string body)
{
	_body += body;
}

/* ************************************************************************** */