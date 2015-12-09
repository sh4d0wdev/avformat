require "bundler/gem_tasks"
require "rspec/core/rake_task"
require "rake/extensiontask"

RSpec::Core::RakeTask.new(:spec)


Rake::ExtensionTask.new "avformatext" do |ext|
    ext.lib_dir ="lib/avformat"
end

task :default => [:compile, :spec]


