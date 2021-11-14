using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace API.Errors
{
    public class ApiException
    {
        public ApiException(int statusCode, string message = null, string details = null)
        {
            StatusCode = statusCode;
            Message = message;
            Detailed = details;
        }
        public int StatusCode { get; set; }
        public string Message { get; set; }
        public string Detailed { get; set; }

    }
}