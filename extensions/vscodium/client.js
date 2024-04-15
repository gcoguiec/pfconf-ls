try {
  module.exports = require('./out/main');
} catch {
  module.exports = require('./dist/client');
}
