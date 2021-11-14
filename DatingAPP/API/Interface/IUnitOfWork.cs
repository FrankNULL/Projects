using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace API.Interface
{
    public interface IUnitOfWork
    {
        IUserRepository UserRepository {get;}

        IMessageRepository MessageRepository{get;}

        ILikesRepository LikesRepository{get;}
        Task<bool> Complete();
        bool HasChanges();
    }
}